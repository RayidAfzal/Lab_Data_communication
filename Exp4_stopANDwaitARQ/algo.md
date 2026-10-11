
# Algorithm: Stop-and-Wait ARQ

1. Start.
2. Read the number of frames `n`.
3. Repeat for each frame from 1 to `n`.
4. Display the frame being sent.
5. Read the ACK status (1 = received, 0 = lost).
6. If ACK is 1, display acknowledgement received and proceed to the next frame.
7. Otherwise, retransmit the frame and read the ACK again.
8. If the second ACK is 1, proceed to the next frame; otherwise, display transmission failure.
9. Display the completion message.
10. Stop.



# Pseudocode: Stop-and-Wait ARQ

START
    Read number of frames n

    FOR i = 1 TO n
        Display "Sending Frame i"
        Read ACK

        IF ACK = 1 THEN
            Display "ACK received"
        ELSE
            Display "Frame lost; retransmit frame"
            Read ACK

            IF ACK = 1 THEN
                Display "ACK received"
            ELSE
                Display "Transmission failed"
            END IF
        END IF
    END FOR

    Display "All frames transmitted successfully"
STOP
