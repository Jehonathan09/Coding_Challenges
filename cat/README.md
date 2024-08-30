# Build Your Own `cat` Tool

This repository contains a coding challenge to build your own version of the Unix command-line tool `cat`. The `cat` utility is a simple yet powerful tool used to read files sequentially and write their contents to the standard output. By creating our own version, we can deepen our understanding of software engineering principles and the Unix philosophy.

## Challenge Overview

### Unix Philosophy
- **Write simple parts connected by clean interfaces:** Each tool should do one thing well, with a simple command-line interface that handles text input from files or streams.
- **Design programs to be connected:** Each tool can easily connect with others, allowing for complex text processing pipelines from simple tools.

### The `cat` Tool
The `cat` tool reads files and outputs their contents in the order specified. If no files are specified or if a dash (`-`) is provided as a file, `cat` reads from the standard input.

### Steps to Build Your Own `cat` Tool

#### Step 0: Setup
Before diving into the challenge, set up your development environment with your preferred IDE/editor and programming language. Once you're ready, grab some test data using the following commands:

```bash
curl "https://dummyjson.com/quotes?limit=10" | jq '.quotes | .[] | .quote' > test.txt
curl "https://dummyjson.com/quotes?limit=10&skip=10" | jq '.quotes | .[] | .quote' > test2.txt
```

#### Step 1: Basic File Output
Your goal is to open a file specified on the command line and write its contents to the standard output.

**Example:**

```bash
cccat test.txt
```

Expected output:

```plaintext
"Life isn’t about getting and having, it’s about giving and being."
"Whatever the mind of man can conceive and believe, it can achieve."
...
```

#### Step 2: Handle Standard Input
Modify your program to read input from standard input if no file is specified or if the dash (`-`) is used as a file.

**Example:**

```bash
head -n1 test.txt | cccat -
```

Expected output:

```plaintext
"Life isn’t about getting and having, it’s about giving and being."
```

#### Step 3: Concatenate Files
Extend your program to handle multiple files, concatenating their contents.

**Example:**

```bash
cccat test.txt test2.txt
```

Expected output:

```plaintext
"Life isn’t about getting and having, it’s about giving and being."
"Whatever the mind of man can conceive and believe, it can achieve."
...
"Eighty percent of success is showing up."
```

#### Step 4: Line Numbering
Add the ability to number the lines as they are printed out.

**Example:**

```bash
head -n3 test.txt | cccat -n
```

Expected output:

```plaintext
1  "Life isn’t about getting and having, it’s about giving and being."
2  "Whatever the mind of man can conceive and believe, it can achieve."
3  "Strive not to be a success, but rather to be of value."
```

#### Step 5: Advanced Line Numbering
Enhance your tool to support numbering both all lines and only non-blank lines.

**Example:**

```bash
sed G test.txt | cccat -n | head -n4
```

Expected output:

```plaintext
1  "Life isn’t about getting and having, it’s about giving and being."
2
3  "Whatever the mind of man can conceive and believe, it can achieve."
4
```

Another Example:

```bash
sed G test.txt | cccat -b | head -n5
```

Expected output:

```plaintext
 1  "Life isn’t about getting and having, it’s about giving and being."

 2  "Whatever the mind of man can conceive and believe, it can achieve."

 3  "Strive not to be a success, but rather to be of value."
```


