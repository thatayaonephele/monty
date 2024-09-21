>,------------------------------------------------   # Read and adjust the first number (ASCII '0' to '9') into block #1
>,------------------------------------------------   # Read and adjust the second number (ASCII '0' to '9') into block #2

[->+<]      # Transfer the value from block #2 to block #0 and clear block #2
[->+<]      # Transfer the value from block #1 to block #0 and clear block #1

++++++++++++++++++++++++++++++++++++++++++++++++    # Reconvert the result in block #0 to ASCII by adding 48
.              # Output the final value in block #0
