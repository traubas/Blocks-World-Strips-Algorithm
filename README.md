# Blocks-World-Strips-Algorithm
made for AI course for Haifa University

just implementing the STRIPS algorithm we learned in AI course at the uni...

IMPORTANT: this is more than STRIPS algorthim,
since i used some heuristics to solve problems that STRIPS does NOT solve
(like changing the way we insert the goal stack commands)

# How to Use:

when prompted:
 - please enter number of blocks:
 
 +if you will insert 10 for example,
 +the program will create a 10 by 10 array,
 +and will let you use 10 blocks
 +with the names: A,B,C,D,E,F,G,H,I
 
 [currently the program supports up to 10 blocks]
 
 - enter the initial state, enter 1 to continue:

 this part we set the initial state of the blocks on the table,
 for instance, if you input:
 - ABC
 the program will set the blocks A,B,C on the table in such a way that
 C is ONTABLE
 B ON C
 A ON B
 so a valid input will be:
 - ABC
 - DEF
 - GH
 - I
 after each stack click ENTER to enter the next stack.
 when finished enter:
 - 1 (one)

The program will then show you how the table looks the way you input the initial state.
click ENTER.

 - now enter the goal state:
 same as before but this time set the state to what you want it to be when the algorithm finishes.
 
#NEXT

after the input stage
just click ENTER to advance throught the algorithm
the algorithm uses a STACK of commands that looks something like that:
|AB|
|BC|
|__|
which means on the top of the stack is the next command: PUT: A ON B
and the next command on the stack is PUT: B ON C
if the algorithm sees:
AB
it will be translated to the set of necessary conditions for it to happen.
READ about STRIPS algorithm to know how it works.



 
 
 