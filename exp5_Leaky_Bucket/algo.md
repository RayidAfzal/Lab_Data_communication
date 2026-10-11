
# Algorithm: Leaky Bucket Algorithm

1. Start.
2. Generate and display random packet sizes.
3. Read the bucket capacity and output rate.
4. Initialize the remaining packet size to zero.
5. For each packet, check whether it exceeds the available bucket capacity.
6. If capacity is exceeded, reject the packet.
7. Otherwise, add the packet to the bucket.
8. Transmit packets at the specified output rate until the transmission time expires or the bucket becomes empty.
9. Display the remaining bytes after each transmission.
10. Repeat for all packets.
11. Stop.



# Pseudocode: Leaky Bucket Algorithm

START
    Generate random packet sizes
    Display packet sizes
    Read bucket capacity
    Read output rate
    Set remaining size = 0

    FOR each packet
        IF packet size + remaining size > bucket capacity THEN
            Reject packet
        ELSE
            Add packet size to remaining size
            Generate transmission time

            WHILE transmission time remains
                IF remaining size > 0 THEN
                    IF remaining size <= output rate THEN
                        Transmit all remaining bytes
                        Set remaining size = 0
                    ELSE
                        Transmit output rate bytes
                        Subtract output rate from remaining size
                    END IF
                ELSE
                    Display no packets to transmit
                END IF
            END WHILE
        END IF
    END FOR
STOP
