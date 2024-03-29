# MyPass - CLI Password Manager

MyPass is a command-line interface (CLI) password manager that allows users to securely store, retrieve, update, and delete passwords for various accounts. It uses AES encryption to protect the password data stored in a file on the local system.

## Features

- Add new passwords: Users can add passwords along with associated details such as username, email, and source.
- Get passwords: Users can retrieve passwords for specific sources.
- Update passwords: Users can update existing passwords.
- Delete passwords: Users can delete passwords for specific sources.

## Prerequisites

- C++ compiler
- Crypto++ library
- Linux operating system (for file operations, can be modified for other OS)

## Installation

1. Clone the repository to your local machine:

2. Compile the code using your C++ compiler:

3. Run the executable:


## Usage

Follow the on-screen prompts to perform various actions:

1. Choose an action by entering the corresponding number.
2. For adding, updating, or deleting passwords, follow the instructions provided.
3. For getting a password, enter the source for which you want to retrieve the password.

## Security

- MyPass encrypts password data using AES encryption with a user-provided password.
- Passwords are stored locally on the user's machine, ensuring data privacy.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

