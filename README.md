# Bank Management System in C
A menu-driven banking application developed in C to simulate basic banking operations, including account creation, password-based login, deposits, withdrawals, and money transfers

## Overview
The Secure Bank Management System is a console-based application designed to demonstrate the implementation of basic banking operations using C programming. It provides an interactive menu through which users can create accounts, authenticate using account credentials, manage balances, and transfer money between accounts.

The project applies structured programming concepts, string handling, arrays, functions, and input validation to manage customer account information and perform balance-related operations.

### Features
1. Create New Account: Register a customer with a name, unique 12-digit account number, password, mobile number, and address.
2. Password Confirmation: Verify the password during account creation by checking it against the confirmation password.
3. Account Login: Authenticate users by matching their account number and password.
4. Deposit Money: Add a specified amount to an existing account balance.
5. Withdraw Money: Withdraw funds after checking the available balance and validating the withdrawal amount.
6. Transfer Money: Transfer funds between two different accounts while checking the sender's balance and preventing transfers to the same account.
7. Display Account Information: View account numbers, customer names, mobile numbers, addresses, and balances in a structured table.
8. Input Validation: Validate account number length, numeric account numbers, mobile number format, duplicate account numbers, duplicate mobile numbers, and transaction amounts.

### Technologies and Concepts
1. Programming Language - C
2. Header Files - stdio.h, string.h
3. Compiler - GCC
4. Data Storage - Structures and arrays
5. String Operations - strcmp(), strcpy(), strlen()
6. Programming Concepts - Functions, pointers, loops, and conditional statements
7. Input Validation - Account numbers, mobile numbers, and transaction amounts
8. Version Control - Git and GitHub

### Future Enhancements
1. Implement file handling to retain account information between program executions.
2. Require authentication before account-specific banking transactions.
3. Add transaction history for deposits, withdrawals, and transfers.
4. Improve input validation and handling of invalid or oversized input.
5. Introduce secure password storage and stronger authentication mechanisms.
6. Add account statements and transaction summaries.

### Learning Outcomes
1. Structures and arrays for managing account records.
2. Functions and pointers for organizing program logic.
3. String manipulation and comparison using the C standard library.
4. Conditional statements and loops for menu-driven applications.
5. Searching for accounts using account numbers.
6. Input validation and balance updates during banking transactions.

### Author
Developed as a hands-on C programming project to strengthen programming fundamentals, logical thinking, and problem-solving skills.
