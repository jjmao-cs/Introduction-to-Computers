# The Tortoise and the Hare

## Description and Quest
- In this problem, you will recreate one of the truly great moment in history, namely the classic race of the tortoise and the hare.
- You will use random number generation to develop a simulation of this memorable event.
- Our  contenders begin the race at “square 1” of 70 squares.
- Each square represents a possible position along the race course. 
- The finish line is at square 70.
- The first contender to reach or pass square 70 is rewarded with a pail of fresh carrots and lettuce.
- The course weaves its way up the side of a slippery mountain, so occasionally the contenders lose ground.
- There’s a clock that ticks once per second. With each tick of the clock, your program should adjust the position of the animals according to the rules of the following figure.

| Animal |  Move type | Percentage of the time | Actual move |
|---|---|---|---|
|Tortoise|Fast plod|50%|3 squares forward|
||Slip|20%|6 squares backward|
||Slow plod|30%|1 square forward|
||||
|Hare|Sleep|20%|No move at all|
||Big hop|20%|9 squares forward|
||Big slip|10%|12 squares backward|
||Small hop|30%|1 square forward|
||Small slip|20%|2 squares backward|

## Reference
- C How to Program (Eighth Edition) Authors: Paul J. Deitel and Harvey M. Deitel. Publisher: Prentice Hall (2016)..
