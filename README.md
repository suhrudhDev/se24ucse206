 Memory Game (Concentration) - C Implementation

 Overview
The Memory Game (also known as Concentration) is a card-matching game where players need to find pairs of matching cards by flipping them over two at a time. The game is played on a grid, and the objective is to match pairs of identical cards.

This is a console-based version of the game, implemented in C. The game features card shuffling, board display, and player interaction for a fun experience.

 Features
- *Card Shuffling*: The cards are shuffled randomly at the start of the game.
- *Board Display*: The board is displayed with hidden cards marked as * and revealed cards showing their values.
- *Player Interaction*: Players select two cards at a time to try to match them. The game will notify if the cards match or not.
- *Matching Logic*: If a player matches two cards, they remain face-up. Otherwise, they are hidden again.
- *Game Over*: The game ends when all pairs of cards are matched.


 Execution

 1. Run the Game
Once compiled, you can run the game by typing:

bash
./memory_game


Follow the on-screen prompts to select cards and try to match pairs.

Gameplay Instructions
1. *Game Setup*: Upon starting the game, the board will display hidden cards (*). 
2. *Card Selection*: The player will be prompted to enter the coordinates (row and column) of two cards they wish to flip.
   - Example: 0 1 selects the card at row 0, column 1.
3. *Matching*: If the two selected cards match, they will remain face-up. If they do not match, they will be hidden again, and the player will need to select two new cards.
4. *Game Over*: The game ends when all pairs are matched. The number of moves taken to complete the game is displayed.

 Example Gameplay


Board:
*	*	*	*	
*	*	*	*	
*	*	*	*	
*	*	*	*	

Select the first card (row and column): 0 0
Select the second card (row and column): 1 1

Board:
1	*	*	*	
*	2	*	*	
*	*	*	*	
*	*	*	*	

Not a match. Try again.

Select the first card (row and column): 0 1
Select the second card (row and column): 1 0

...

Congratulations! You've matched all pairs in 10 moves.


 Game Logic

1. The board is a 4x4 grid with 8 pairs of matching cards.
2. Each player selects two cards by entering the row and column indices.
3. If the two selected cards match, they remain revealed. If they don't, they are flipped back over.
4. The game ends when all pairs are matched, and the number of moves is displayed.

 File Structure

- memory_game.c: The main C source code file for the Memory Game.
- README.md: This file containing instructions and information about the game.

