# 🔍 Inverted Search Engine in C

A Data Structures & Algorithms project implemented in **C** that builds an **Inverted Index** for efficient word searching across multiple text files. This project was developed as part of my learning journey at **Emertxe Information Technologies**.

---

## 📖 Project Overview

An **Inverted Search Engine** stores words along with the list of files in which they appear. Instead of scanning every file for each search, the application creates a searchable database using **Hash Tables** and **Linked Lists**, making retrieval much faster and more organized.

### Example

If the input files contain:

**f1.txt**

```
hello hi hello
```

**f2.txt**

```
hello hi
```

Searching for **hello** returns:

```
Word : hello
Found in 2 file(s)

f1.txt  →  2 times
f2.txt  →  1 time
```

---

## ✨ Features

* 📂 Validate input text files
* ❌ Detect invalid extensions, empty files, and duplicate files
* #️⃣ Create an inverted index using a Hash Table (27 buckets)
* 🔗 Store data using Main Node & Sub Node linked lists
* 🔍 Search words with occurrence count
* 📊 Display the complete database
* 💾 Save the database into a backup file
* ♻️ Update/Restore the database from a backup file
* 🧩 Modular implementation with separate source files

---

## 🛠️ Data Structures Used

* **Hash Table** – Fast indexing based on the first character
* **Linked List** – File list management
* **Main Node** – Stores word and file count
* **Sub Node** – Stores filename and word occurrence
* **Dynamic Memory Allocation** – Efficient memory management

---

## 📁 Project Structure

```text
DSA_2_INVERTED_SEARCH/
│
├── main.c
├── create.c
├── display.c
├── search.c
├── save.c
├── update.c
├── validations.c
├── inverted.h
├── Makefile
└── README.md
```

---

## ⚙️ Operations

| Option | Description      |
| ------ | ---------------- |
| 1      | Create Database  |
| 2      | Display Database |
| 3      | Save Database    |
| 4      | Search Word      |
| 5      | Update Database  |
| 6      | Exit             |

---

## 🚀 How to Compile

```bash
make
```

Or

```bash
gcc -o inverted.exe main.c create.c display.c search.c save.c update.c validations.c
```

---

## ▶️ How to Run

```bash
./inverted.exe f1.txt f2.txt
```

### Create Database

```text
Enter your choice : 1

Database created successfully
```

### Search

```text
Enter your choice : 4
Enter the word : hello

Word hello is present in 2 file(s)
```

### Save

```text
Enter your choice : 3
Enter file name : backup.txt
```

### Update

```text
Enter your choice : 5
Enter backup file : backup.txt

Database updated successfully
```

---

## 🧠 Learning Outcomes

Through this project, I gained practical experience in:

* Hash Tables
* Linked Lists
* File Handling
* Dynamic Memory Allocation
* Pointers
* Modular Programming in C
* Efficient Text Indexing

---

## 🌍 Real-World Applications

* Search Engines
* Document Indexing
* Digital Libraries
* Messaging App Search
* Log File Analysis

---

## 👩‍💻 Author

**B. Mamatha Reddy**

ECE Student | Embedded Systems & Advanced C Enthusiast

---

⭐ If you found this project interesting, consider giving the repository a **Star**!
