
# Algorithm: Go-Back-N ARQ

1. Start.
2. Read the number of frames, window size, and frame number to simulate loss.
3. Initialize the starting frame to 0.
4. Calculate the end of the current window.
5. Display the frames sent by the sender.
6. If a lost frame belongs to the current window:
   - Display the lost frame and timeout.
   - Retransmit the lost frame and all subsequent frames in the window.
   - Display the acknowledgement.
7. Otherwise, acknowledge all frames in the window.
8. Move to the next window.
9. Repeat until all frames are processed.
10. Display the completion message and stop.




# Pseudocode: Go-Back-N ARQ

START
    Read n, window size, and lost frame
    Set start = 0

    WHILE start < n
        Set end = minimum(start + window size, n)
        Display frames in the current window

        IF lost frame belongs to current window
            Display frame loss and timeout
            Retransmit lost frame and subsequent frames
            Display acknowledgement
            Set lost frame = -1
        ELSE
            Acknowledge all frames in the window
        END IF

        Set start = end
    END WHILE

    Display completion message
STOP
