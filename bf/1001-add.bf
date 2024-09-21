>,------------------------------------   # Read and adjust the first number (ASCII to number) into block #1
>,------------------------------------   # Read and adjust the second number (ASCII to number) into block #2

[>>+<<-]    # Move the value from block #2 to block #0, then clear block #2
<[>-<+>]    # Move the value from block #1 to block #0, clearing block #1 after
<++++++++++++++++++++++++++++++++++++   # Reconvert the result in block #0 to ASCII by adding 48
.           # Output the final value from block #0
