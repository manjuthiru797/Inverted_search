# Inverted Search Using C

## Project Summary
Inverted Search is a file-based searching application developed in C. It creates an inverted index to efficiently search for words across multiple text files.

Instead of scanning every file whenever a search is performed, the application maintains an index that stores words along with the files in which they appear and their frequency.

## Overview
An inverted index is a data structure that maps each word to the documents or files containing that word.

For example:

**Input Files:**

- file1.txt: `Embedded systems are interesting`
- file2.txt: `Embedded systems use microcontrollers`

**Inverted Index:**

| Word | File | Word Count |
|---|---|---:|
| Embedded | file1.txt | 1 |
| Embedded | file2.txt | 1 |
| systems | file1.txt | 1 |
| systems | file2.txt | 1 |
| interesting | file1.txt | 1 |
| microcontrollers | file2.txt | 1 |

This structure makes keyword-based searching more efficient.

## Problem Statement
Searching for a particular word across multiple files by reading each file repeatedly can be time-consuming.

The objective of this project is to implement an inverted index that stores word-to-file relationships and allows faster searching of keywords.

## Technologies Used
- Programming Language: C
- Data Structures: Hash Table, Linked Lists
- Concepts: File Handling, Dynamic Memory Allocation, String Manipulation, Pointers
- Indexing Technique: Inverted Indexing

*Adjust the data structures according to your actual implementation.*

## Features

### 1. Create Database
- Read data from the input text files.
- Extract individual words.
- Create an inverted index.
- Store word occurrences and corresponding file information.

### 2. Display Database
- Display the indexed words.
- Show the associated filenames.
- Display the occurrence count of each word.

### 3. Search Database
- Accept a keyword from the user.
- Search for the keyword in the database.
- Display the files containing the keyword and its occurrence count.

### 4. Update Database
- Add additional files or update the existing database, if supported by the implementation.

### 5. Save Database
- Store the created database in a file for future use, if supported.

## Working Methodology

1. **Input:** Accept multiple text files.
2. **Validation:** Check the input files.
3. **Extraction:** Read the files and extract individual words.
4. **Indexing:** Store each word along with its associated filename and frequency.
5. **Searching:** Search for a requested keyword in the index.
6. **Display:** Show the matching files and word counts.

## Data Structure Representation

The inverted index can be represented using a hash table and linked lists.

```text
Hash Table
    |
    v
  [Word]
    |
    v
 File Linked List
    |
    +----> File 1 (Word Count)
    |
    +----> File 2 (Word Count)
    |
    +----> File 3 (Word Count)
```

Each word is stored in the index, and its linked list maintains the associated file information.

## Key Concepts Learned
- Inverted indexing
- Hash tables
- Linked lists
- File operations in C
- Dynamic memory allocation
- String manipulation
- Pointers and structures
- Searching and indexing techniques

## Applications
- Search engines
- Document management systems
- File searching applications
- Information retrieval systems
- Text indexing applications

## How to Run

1. Clone the repository:

   ```bash
   git clone <repository-url>
   ```

2. Navigate to the project directory:

   ```bash
   cd <project-folder>
   ```

3. Compile the C source files:

   ```bash
   gcc *.c -o inverted_search
   ```

4. Run the executable:

   ```bash
   ./inverted_search
   ```

*Update the compilation command according to your source-file structure.*

## Future Improvements
- Support for larger collections of files
- Case-insensitive searching
- Improved search performance
- Support for phrase searching
- Database persistence and restoration
- Search ranking based on word frequency

## Conclusion
This project demonstrates the implementation of an inverted index using C programming and data structures. It provides practical experience in file handling, linked lists, hash tables, dynamic memory allocation, and efficient keyword searching.

## Author
**Manjusha Thiruveedhula**
