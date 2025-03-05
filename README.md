# Simple-Vending-Machine-Sim
C++ - CIS22B A4

Create a program that simulates a simple vending machine that sells chips, candy, and soda. Each of these snacks has a different price and will have a different amount in stock. When the program is running, the current contents of the vending machine will 
be displayed to the user, and then a prompt to enter a number of quarters will appear. After the user enters a number, the amount of money they entered will appear in dollars and cents. For example, if the user entered 7 quarters, $1.75 would be displayed. Next, the user will be 
prompted to make a selection from the vending machine. If they have entered enough money and the snack is in-stock, the item will be dispensed, and the number in-stock will decrease by one. If the user entered more money than necessary to make the purchase, a message will be 
displayed indicated that the appropriate amount of change has been returned.

```
Welcome to the vending machine!

Item #    ItemName  Price     # in-stock
----------------------------------------
1         Chips     1.75      3         
2         Candy     1.25      5         
3         Soda      1         2         
Enter the number of quarters: -1
Please enter a number greater than 0

Enter the number of quarters: 8
Amount Entered: $2.00

Enter a number between 1 and 3 to make your selection: 3
Item has been dispensed below
$1.00 dispensed below

Continue? (Y / N): y

Item #    ItemName  Price     # in-stock
----------------------------------------
1         Chips     1.75      3         
2         Candy     1.25      5         
3         Soda      1.00      1         
Enter the number of quarters: 4
Amount Entered: $1.00

Enter a number between 1 and 3 to make your selection: 3
Item has been dispensed below

Continue? (Y / N): y

Item #    ItemName  Price     # in-stock
----------------------------------------
1         Chips     1.75      3         
2         Candy     1.25      5         
3         Soda      1.00      0         
Enter the number of quarters: 4
Amount Entered: $1.00

Enter a number between 1 and 3 to make your selection: 3
Error: item is sold-out!
$1.00 dispensed below

Continue? (Y / N): y

Item #    ItemName  Price     # in-stock
----------------------------------------
1         Chips     1.75      3         
2         Candy     1.25      5         
3         Soda      1.00      0         
Enter the number of quarters: 10
Amount Entered: $2.50

Enter a number between 1 and 3 to make your selection: 1
Item has been dispensed below
$0.75 dispensed below

Continue? (Y / N): y

Item #    ItemName  Price     # in-stock
----------------------------------------
1         Chips     1.75      2         
2         Candy     1.25      5         
3         Soda      1.00      0         
Enter the number of quarters: 5
Amount Entered: $1.25

Enter a number between 1 and 3 to make your selection: 2
Item has been dispensed below

Continue? (Y / N): y

Item #    ItemName  Price     # in-stock
----------------------------------------
1         Chips     1.75      2         
2         Candy     1.25      4         
3         Soda      1.00      0         
Enter the number of quarters: 9
Amount Entered: $2.25

Enter a number between 1 and 3 to make your selection: 1
Item has been dispensed below
$0.50 dispensed below

Continue? (Y / N): n

Closing info for Soda
0 in stock
2 sold for a profit of $2.00

Transactions occurred at:
        23:43:40
        23:43:53
Closing info for Candy
4 in stock
1 sold for a profit of $1.25

Transactions occurred at:
        23:44:31
Closing info for Chips
1 in stock
2 sold for a profit of $3.50

Transactions occurred at:
        23:44:21
        23:44:44
```
