import simplegui
import random

# load card sprite - 936x384 - source: jfitz.com
CARD_SIZE = (72, 96)
CARD_CENTER = (36, 48)
card_images = simplegui.load_image("http://storage.googleapis.com/codeskulptor-assets/cards_jfitz.png")

CARD_BACK_SIZE = (72, 96)
CARD_BACK_CENTER = (36, 48)
card_back = simplegui.load_image("http://storage.googleapis.com/codeskulptor-assets/card_jfitz_back.png")    

# initialize some useful global variables
in_play = False
outcome = ""
result = ""
score = 0
deck = 0
player_hand = 0
dealer_hand = 0

# define globals for cards
SUITS = ('C', 'S', 'H', 'D')
RANKS = ('A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K')
VALUES = {'A':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, 'T':10, 'J':10, 'Q':10, 'K':10}


# define card class
class Card:
    def __init__(self, suit, rank):
        if (suit in SUITS) and (rank in RANKS):
            self.suit = suit
            self.rank = rank
        else:
            self.suit = None
            self.rank = None
            print("Invalid card: ", suit, rank)

    def __str__(self):
        return self.suit + self.rank

    def get_suit(self):
        return self.suit

    def get_rank(self):
        return self.rank

    def draw(self, canvas, pos):
        card_loc = (CARD_CENTER[0] + CARD_SIZE[0] * RANKS.index(self.rank), 
                    CARD_CENTER[1] + CARD_SIZE[1] * SUITS.index(self.suit))
        canvas.draw_image(card_images, card_loc, CARD_SIZE, [pos[0] + CARD_CENTER[0], pos[1] + CARD_CENTER[1]], CARD_SIZE)
        
# define hand class
class Hand:
    def __init__(self):
        # create Hand object
        self.hand = []	

    def __str__(self):
        # return a string representation of a hand
        hand_str = "Hand contains "
        for card in self.hand:
            hand_str += str(card) + " "
        return hand_str
    
    def add_card(self, card):
        # add a card object to a hand
        self.hand.append(card)	

    def get_value(self):
        # count aces as 1, if the hand has an ace, then add 10 to hand value if it doesn't bust
        value = 0
        hand = [card.get_rank() for card in self.hand]
        for card in hand:
            value += VALUES[card]
        if "A" not in hand:
            return value
        else:
            if value + 10 <= 21:
                return value + 10
            else:
                return value
        
    def draw(self, canvas, pos):
        # draw a hand on the canvas, use the draw method for cards
        hand = list(self.hand)
        for i in range(len(hand)):
            hand[i].draw(canvas, [pos[0] + CARD_SIZE[0]*i, pos[1]])
 
        
# define deck class 
class Deck:
    def __init__(self):
        # create a Deck object
        self.deck = [Card(suit,rank) for suit in SUITS for rank in RANKS]	

    def shuffle(self):
        # shuffle the deck 
        random.shuffle(self.deck)

    def deal_card(self):
        return self.deck.pop(-1)	# deal a card object from the deck
    
    def __str__(self):
        # return a string representing the deck
        deck_str = "Deck contains "
        for card in self.deck:
            deck_str += str(card) + " "
        return deck_str


#define event handlers for buttons
def deal():
    global outcome, in_play, deck, player_hand, dealer_hand, result, score
    outcome = "Hit or stand?"
    result = ""
    
    if in_play:
        result = "You lose"
        score -= 1
    
    in_play = True
    deck = Deck()
    player_hand = Hand()
    dealer_hand = Hand()
    deck.shuffle()
    
    for i in range(2):
        player_hand.add_card(deck.deal_card())
        dealer_hand.add_card(deck.deal_card())

def hit():
    global in_play, outcome, result, score
    
    # if the hand is in play, hit the player
    if in_play:
        player_hand.add_card(deck.deal_card())
        
        # if busted, assign a message to outcome, update in_play and score
        if player_hand.get_value() > 21:
            result = "Busted"
            outcome = "New deal?"
            in_play = False
            score -= 1
        else:
            outcome = "Hit or stand?"
       
def stand():
    global outcome, in_play, result, score
    
    if player_hand.get_value() > 21:
        outcome = "New deal?"
        result = "Busted"
        in_play = False
    # if hand is in play, repeatedly hit dealer until his hand has value 17 or more
    elif in_play:
        while dealer_hand.get_value() <= 17:
            dealer_hand.add_card(deck.deal_card())
        # assign a message to outcome, update in_play and score
        if dealer_hand.get_value() <= 21:
            if player_hand.get_value() <= dealer_hand.get_value():
                result = "You lose"
                score -= 1
            else:
                result = "You win!"
                score += 1
            outcome = "New deal?"
            in_play = False
        else:
            outcome = "New deal?"
            result = "You win!"
            in_play = False
            score += 1
            
def restart():
    global score
    
    score = 0

# draw handler    
def draw(canvas):
    
    player_hand.draw(canvas, [100, 400])
    dealer_hand.draw(canvas, [100, 200])
    
    canvas.draw_text(outcome, [30, 100], 30, 'Red')
    canvas.draw_text(result, [450, 100], 30, 'Red')
    
    canvas.draw_text('Blackjack', [30, 50], 40, 'White')
    canvas.draw_text("Player's hand:", [100, 380], 20, 'White')
    canvas.draw_text("Dealer's hand:", [100, 180], 20, 'White')
    canvas.draw_text("Hand value: " + str(player_hand.get_value()), [100, 520], 20, 'White')
    canvas.draw_text(str(score), [550, 50], 50, 'White')
    
    if in_play:
        canvas.draw_image(card_back, CARD_BACK_CENTER, CARD_BACK_SIZE, [100 + CARD_CENTER[0], 200 + CARD_CENTER[1]], CARD_BACK_SIZE)
    else:
        canvas.draw_text("Hand value: " + str(dealer_hand.get_value()), [100, 320], 20, 'White')
        
# initialization frame
frame = simplegui.create_frame("Blackjack", 600, 600)
frame.set_canvas_background("Green")

#create buttons and canvas callback
frame.add_button("Deal", deal, 200)
frame.add_button("Hit",  hit, 200)
frame.add_button("Stand", stand, 200)
frame.add_button("Restart", restart, 200)
frame.set_draw_handler(draw)


# get things rolling
deal()
frame.start()