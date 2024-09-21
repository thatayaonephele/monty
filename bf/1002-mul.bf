>,--------------------------------------------   # Read the first digit and store in block #1 (subtract 48 to convert from ASCII)
>,--------------------------------------------   # Read the second digit and store in block #2 (subtract 48 to convert from ASCII)

[>>+<<-]                                        # Copy the value from block #1 into block #3
[<[>+>>+<<<-]                                   # Loop: Copy block #1 to block #0 and block #3 (temp store), then clear block #1
>[<<+>>-]                                       # Add block #3 back into block #1 to restore its original value
<-]                                             # Decrease block #2 and repeat until block #2 reaches zero

<<+++++++++++++++++++++++++++++++++++++++++++   # Add 48 to block #0 (convert back to ASCII)
.                                               # Output the result in block #0
