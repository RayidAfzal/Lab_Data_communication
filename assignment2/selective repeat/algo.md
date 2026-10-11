
# Algorithm: Selective Repeat ARQ

1. Start.
2. Read the number of frames, window size, and frame number to simulate loss.
3. Initialize the starting frame to 0.
4. Calculate the end of the current window.
5. Display the frames sent by the sender.
6. If the lost frame belongs to the current window:
   - Display the lost frame.
   - Acknowledge the other frames.
   - Retransmit only the lost frame.
   - Display its acknowledgement.
7. Otherwise, acknowledge all frames in the window.
8. Move to the next window.
9. Repeat until all frames are processed.
10. Display the completion message and stop.




# Pseudocode: Selective Repeat ARQ

START
    Read n, window size, and lost frame
    Set start = 0

    WHILE start < n
        Set end = start + window size

        IF end > n
            Set end = n
        END IF

        Display frames in current window

        IF lost frame belongs to current window
            Display frame loss
            Acknowledge all other frames
            Retransmit only the lost frame
            Display its acknowledgement
            Set lost frame = -1
        ELSE
            Acknowledge all frames in the window
        END IF

        Set start = end
    END WHILE

    Display all frames transmitted successfully
STOP
