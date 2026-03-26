📒 Address Book System (C Programming)
🚀 Overview

The Address Book System is a console-based application developed in C to store and manage contact details such as name, phone number, and email address. The application uses file handling to ensure data persistence using a CSV file.

This project demonstrates fundamental programming concepts including structures, modular programming, file handling, and input validation.

✨ Features
➕ Add new contacts with validation
🔍 Search contacts by name, phone number, or email
✏️ Edit existing contact details
❌ Delete contacts from the system
📋 Display all contacts in alphabetical order
💾 Persistent storage using CSV file
⚠️ Input validation for data integrity
🔁 Handles duplicate entries and multiple matches
🧭 Menu-driven interface for easy navigation

🛠️ Technologies Used
  C Programming
  Structures
  File Handling (CSV)
  Modular Programming

📂 Project Structure
├── main.c
├── contact.c
├── contact.h
├── file.c
├── validation.c
├── address_book.csv
└── README.md

⚙️ Functional Modules

📁 File Handling
  saveContactsToFile() – Saves contacts into CSV file
  loadContactsFromFile() – Loads contacts from CSV file
📋 Contact Management
  createContact() – Add new contacts
  searchContact() – Search contacts
  editContact() – Modify contact details
  deleteContact() – Remove contacts
🔎 Search Operations
  search_name()
  search_number()
  search_mail()
✅ Validation
  valname() – Validates name
  valnum() – Validates phone number
  valmail() – Validates email
✍️ Input Functions
  enter_name()
  enter_number()
  enter_email()
⚠️ Challenges Faced
  Maintaining data consistency during edit and delete operations
  Preventing duplicate entries
  Handling invalid inputs and empty records
  Managing file pointers effectively

📚 Learning Outcomes
  Improved understanding of file handling and data persistence
  Gained experience in modular coding and program structuring
  Learned defensive programming techniques
  Strengthened debugging and validation logic
  
📌 Future Improvements
  Add GUI interface
  Support for more file formats
  Advanced search filters
  Integration with database systems

🙌 Acknowledgment
Special thanks to mentors and learning resources that guided me during this project.
