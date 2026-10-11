# Algorithm: Sliding Window Protocol

1. Start.
2. Read the window size `w`.
3. Read the number of frames `f`.
4. Read all the frames.
5. Traverse the frames from 1 to `f`.
6. Display each frame.
7. If `i % w == 0`, display the acknowledgement message.
8. After the loop, if `f % w != 0`, display the final acknowledgement message.
9. Stop.




# Pseudocode: Sliding Window Protocol

START
    Read window size w
    Read number of frames f
    Read frames into array

    FOR i = 1 TO f
        IF i MOD w = 0 THEN
            Display frame[i]
            Display acknowledgement received
        ELSE
            Display frame[i]
        END IF
    END FOR

    IF f MOD w != 0 THEN
        Display acknowledgement received
    END IF
STOP
