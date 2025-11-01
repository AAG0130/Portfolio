# input will come from buttons and an input field
# all output for the game will be printed in the console
import simplegui
import random

secret_number = 0
num_range = (0, 100)
n = 0


# helper function to start and restart the game
def new_game():
    global secret_number
    global n
    
    if num_range[1] == 100:
        n = 7
    else:
        n = 10
    
    secret_number = random.randrange(num_range[0], num_range[1])
    print("New game. Range is from " + str(num_range[0]) + " to " + str(num_range[1]))
    print("Number of remaining guesses is " + str(n))

# define event handlers for control panel
def range100():
    # button that changes the range to [0,100) and starts a new game 
    global num_range
    global n
    
    num_range = (0, 100)
    
    new_game()
    

def range1000():
    # button that changes the range to [0,1000) and starts a new game     
    global num_range
    global n
    
    num_range = (0, 1000)
    
    new_game()
    
    
def input_guess(guess):
    global n
    
    n -= 1
    guess_int = int(guess)
    print("Guess was " + guess)
    
    if n == 0 and guess_int != secret_number:
        print("Out of guesses")
        new_game()
    elif guess_int > secret_number:
        print("Number of remaining guesses is " + str(n))
        print("Lower")
    elif guess_int < secret_number:
        print("Number of remaining guesses is " + str(n))
        print("Higher")
    else:
        print("Correct")
        new_game()
    
# create frame
frame = simplegui.create_frame("Guess the number", 200, 200)

# register event handlers for control elements and start frame
range_1_100 = frame.add_button("Range is [0,100)", range100, 200)
range_1_1000 = frame.add_button("Range is [0,1000)", range1000, 200)
inp = frame.add_input("Enter a guess", input_guess, 200)

# call new_game 
new_game()

frame.start()