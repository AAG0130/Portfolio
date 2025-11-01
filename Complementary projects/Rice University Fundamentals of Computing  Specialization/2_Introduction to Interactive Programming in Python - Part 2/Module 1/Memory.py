import simplegui
import random

state = 0
card_1 = 0
card_2 = 0
counter = 0

exposed = [False for n in range(16)]
#exposed[0], exposed[8] = True, True

card_deck = list(range(8)) + list(range(8))
random.shuffle(card_deck)


# helper function to initialize globals
def new_game():
    global state
    global counter
    global card_deck
    global exposed
    
    state = 0
    counter = 0
    random.shuffle(card_deck)
    exposed = [False for n in range(16)]

# define event handlers
def mouseclick(pos):
    # add game state logic here 
    global state
    global card_1
    global card_2
    global counter
    
    if state == 0 and exposed[pos[0]//50] == False:
        state = 1
        counter += 1
        card_1 = pos[0]//50
        exposed[pos[0]//50] = True
    elif state == 1 and exposed[pos[0]//50] == False:
        state = 2
        card_2 = pos[0]//50
        exposed[pos[0]//50] = True
    elif state == 2 and exposed[pos[0]//50] == False:
        if card_deck[card_1] != card_deck[card_2]:
            exposed[card_1], exposed[card_2] = False, False
        state = 1
        counter += 1
        card_1 = pos[0]//50
        exposed[pos[0]//50] = True
                        
# cards are logically 50x100 pixels in size    
def draw(canvas):
    
    label.set_text("Turns = " + str(counter))
    for index in range(len(card_deck)):
        if exposed[index] == False:
            point_list = [[index*50,0],[(index+1)*50,0],[(index+1)*50,100],[index*50,100]]
            canvas.draw_polygon(point_list,3,"White","Green")
        else:
            canvas.draw_text(str(card_deck[index]),((index*50)+5,75),80,"White")

# create frame and add a button and labels
frame = simplegui.create_frame("Memory", 800, 100)
frame.add_button("Reset", new_game)
label = frame.add_label("Turns = 0")

# register event handlers
frame.set_mouseclick_handler(mouseclick)
frame.set_draw_handler(draw)

# get things rolling
new_game()
frame.start()