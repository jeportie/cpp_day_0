# Code Review
- Review the diff, report on issues, bugs, and improvements. 
- End with a concise markdown table of any issues found, their solutions, and a risk assessment for each issue if applicable.
- Use emojis to convey the severity of each issue.

## Diff

Since there is no active git diff (working tree is clean), this review will analyze the current state of the codebase in `/root/projects/cpp_day_0`.

### Project Structure
- ex00: Megaphone project (simple string manipulation)
- ex01: PhoneBook project (basic OOP class implementation)
- ex02: Account project (banking simulation)

### Key Files Examined

#### ex00 - Megaphone
- `megaphone.cpp`: Main program that converts input to uppercase
- `utils.hpp/cpp`: String manipulation utilities

#### ex01 - PhoneBook
- `PhoneBook.class.hpp/cpp`: Main class for storing and managing contacts
- `Contact.class.hpp/cpp`: Class representing a single contact
- `colors.hpp`: Color definitions for output formatting

#### ex02 - Account
- `Account.hpp/cpp`: Banking account simulation with transactions
- `tests.cpp`: Test program for the Account class

### Code Analysis

```cpp
// In Contact.class.hpp
private:
    std::string _fistName;  // Typo in field name
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNbr;
    std::string _darkestSecret;
```

```cpp
// In PhoneBook.class.public.cpp
void PhoneBook::addContact()
{
    // ...
    current = PhoneBook::_contacts[_arrIndex % 8];  // Unnecessary creation and copy
    if (!current.setContactInfo(firstName, lastName, nickname, phoneNbr, darkestSecret))
    {
        std::cout << "error: setContactInfo failed" << std::endl;
        return;
    }
    PhoneBook::_contacts[_arrIndex % 8] = current;  // Unnecessary reassignment
    // ...
}
```

```cpp
// In Account.cpp
bool Account::makeWithdrawal(int withdrawal)
{
    // ...
    Account::_amount -= withdrawal;  // Deduction happens before validation
    Account::_displayTimestamp();
    if (Account::_amount < 0)
    {
        Account::_amount = p_amount;  // Needs to restore amount if insufficient
        // ...
    }
    // ...
}
```

```cpp
// In utils.cpp
std::string strCheckSpace(std::string str)  // Function is complex for its purpose
{
    // ...complicated space handling logic...
}
```
