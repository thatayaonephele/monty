# Multiply two digits from the user, with the result being less than 10

# The first number will be placed in block #1 and the second in block #2
# The result will be stored in block #0
# We'll subtract 48 from each digit (ASCII adjustment) before processing

>,--------------------------------------------   # Read the first digit, subtract 48, and store in block #1
>,--------------------------------------------   # Read the second digit, subtract 48, and store in block #2

# Copy block #1 into block #3 and block #0
[->>+<<]                                        # Transfer block #1 into block #3 and block #0
[->+<]                                          # Transfer block #3 back to block #1

# Multiply: add block #1 value to block #0 repeatedly based on block #2's value
[<[>>+<<-]>-]                                   # Loop: add block #1 to block #0, then decrease block #2 until it reaches zero

# Convert the result in block #0 back to ASCII
<<+++++++++++++++++++++++++++++++++++++++++++   # Add 48 to block #0 to convert to ASCII
.                                               # Output the result

