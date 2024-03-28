# MyPass - C++ CLI Password Manager

MyPass is a simple command-line interface (CLI) password manager implemented in C++. It allows users to securely store and manage their passwords.

## Features

- **Add Password**: Add new passwords with associated username and email.
- **Get Password**: Retrieve password details based on the provided source string.
- **Update Password**: (Feature in development) Update existing passwords.
- **Delete Password**: (Feature in development) Delete existing passwords.

## Usage

To use MyPass, follow these steps:

1. Clone or download the repository to your local machine.
2. Compile the source code using a C++ compiler.
3. Run the compiled executable.

Upon running the program, you will be prompted with a menu where you can select various options such as adding, retrieving, updating, or deleting passwords.

## Dependencies

MyPass relies on the following C++ standard libraries:

- iostream
- string
- fstream
- limits

## Usage Example

```bash
$ ./MyPass
============================
   MyPass     
============================

What would you like to do?
 1.) Get Password 
 2.) Add Password 
 3.) Update Password 
 4.) Delete Password 

Enter the corresponding number: 2

Where is this password used?
[Enter the source]

What is the username linked to this password? If there is none press just press enter.
[Enter username]

What is the password?
[Enter password]

What is the email associated with this Account?
[Enter email]

Password added successfully!

