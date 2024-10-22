# Biquadris
Biquadris is a two-player, turn-based variation of the classic Tetris game. Unlike traditional Tetris, Biquadris allows players to take their time to decide block placement, making it more strategic. The game supports both text-based and graphical displays, along with multiple difficulty levels and special actions to enhance gameplay.


## Gameplay
### Game Rules
The board is 11 columns wide and 15 rows high, with three extra rows for block rotation.
Players alternate turns, dropping tetrominoes on their boards.
The game ends when a player cannot place a block on their board.

#### Controls
Move: left, right, down
Rotate: clockwise, counterclockwise
Drop: drop
Change Level: levelup, leveldown
Restart Game: restart
You can prefix commands with a multiplier to repeat them. For example, 3left moves the block three steps to the left.

#### Difficulty Levels
Level 0: Blocks appear in a predetermined sequence from a file.
Level 1: Skewed probabilities favoring S and Z blocks.
Level 2: Equal probabilities for all blocks.
Level 3: Similar to Level 1 but with heavy blocks that automatically drop one row after each command.
Level 4: Adds 1x1 blocks to the board if rows are not cleared after placing five blocks.
#### Special Actions
Blind: Covers a section of the opponent's board until their next drop.
Heavy: Forces the opponent’s block to drop two rows after each move.
Force: Changes the opponent’s block to a chosen type.

## License
Distributed under the MIT License. See LICENSE for more information.

Feel free to modify this template to match your specific implementation or preferences.
