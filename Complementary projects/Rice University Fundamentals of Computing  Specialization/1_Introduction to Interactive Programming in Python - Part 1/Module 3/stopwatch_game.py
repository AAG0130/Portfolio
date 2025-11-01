import simplegui

# define global variables
n = 0
tries = 0
wins = 0
running = False

# define helper function format that converts time
# in tenths of seconds into formatted string A:BC.D
def format(t):
    min = t//600
    remainder = t%600
    tens_scs = remainder//100
    remainder %= 100
    scs = remainder//10
    remainder %= 10
    tenths_scs = remainder
    
    string = str(min) + ":" + str(tens_scs) + str(scs) + "." + str(tenths_scs)
    return string
    
# define event handlers for buttons; "Start", "Stop", "Reset"
def start():
    timer.start()

def stop():
    global tries
    global wins
    global running
    
    running = timer.is_running()
    
    if running:
        tries += 1
        if n%10 == 0:
            wins += 1
        
    timer.stop()

def reset():
    global n
    global tries
    global wins
    
    timer.stop()
    n = 0
    tries = 0
    wins = 0

# define event handler for timer with 0.1 sec interval
def timer_handler():
    global n
    
    n +=1

# define draw handler
def draw_handler(canvas):
    canvas.draw_text(format(n), (150, 215), 40, 'White')
    canvas.draw_text(str(wins) + "/" + str(tries), (350,50), 30, "Green")
    
# create frame
frame = simplegui.create_frame("Stopwatch", 400, 400)

# register event handlers
timer = simplegui.create_timer(100, timer_handler)
start_button = frame.add_button('Start', start, 100)
stop_button = frame.add_button('Stop', stop, 100)
reset_button = frame.add_button('Reset', reset, 100)
frame.set_draw_handler(draw_handler)

# start frame
frame.start()