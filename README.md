# CS 1428 Semester Project Proposal
Student Name: Md Siam Ahmed <br>
Course: CS 1428 – Foundations of Computer Science I (Honor) <br>
Date: October 26, 2025 <br>
## 1. Project Title
### CloudShelf: Intelligent Desktop File Management System
### 2. Project Description
#### What does your project do?
The Smart File Organizer is an automated desktop application that intelligently organizes
cluttered folders (particularly Downloads folders) by analyzing both file metadata and content.
Unlike traditional file organizers that rely solely on file extensions, this system uses content
analysis to understand what files actually contain and categorizes them accordingly.
What problem does it solve?
Most computer users struggle with messy download folders and file systems that become
increasingly disorganized over time. After 6 months to a year, manually organizing hundreds or
thousands of files becomes an overwhelming task. Users often have files with non-descriptive
names (like "document.pdf" or "IMG_1234.jpg") that provide no context about their actual
content.
Example Problem: A file named "abcd.pdf" could be an invoice from September, a recipe, or a
work document. Traditional organizers would only see it as a PDF file, but our system will read
its content, recognize it as an invoice from September, and automatically place it in an
"Invoices/2025/September" folder structure.

### How to use this
1. When you run the program, it will first ask for the folder path you want to organize.

2. After providing the path, the program will automatically organize the files into categorized folders.

3. You may notice a lot of messages printed in the console — these are mainly for debugging purposes and will be removed in the next version.

4. Once the initial organization is complete, the program will ask if you want to organize files based on their modification time.

5. If you select “y”, it will then prompt you to choose the file type to organize:
  - (1) PDF
  - (2) TXT
  - (3) Video
  - (4) Images
6. After selecting a file type, the program will sort those files into “Recent” and “Older” folders accordingly.

### Report on Project Progress

As stated in my initial project proposal, the goal of this project was to develop a program capable of automatically organizing files within a specified folder. During this phase, the core organization engine has been successfully implemented. This engine analyzes each file in the target directory, identifies its type and metadata, and determines the appropriate category for organization.

A basic rule-based system has also been integrated to manage how files are sorted. Based on these rules, the program automatically moves files into folders corresponding to their file types, such as documents, images, videos, or text files. This allows for a cleaner and more structured directory without requiring manual effort.

In addition to the planned features, I have introduced an extra functionality not mentioned in the initial proposal — the ability to sort files based on their modification time. With this feature, users can choose to organize specific file types (such as PDFs, text files, images, or videos) into subfolders labeled “Recent” and “Older,” providing an extra layer of organization and accessibility.

At this stage, all operations are handled through a command-line interface (CLI). The console currently displays detailed debugging information to help track the organization process and ensure proper functionality. These outputs will be refined or removed in the next version once testing is complete.

Overall, the project’s main structure and core logic are functioning as intended, and the additional time-based organization feature enhances its usability beyond the original plan.

### Challenges Faced

One of the main challenges I encountered was storing file data and reusing it later for the organization process. Since I followed a modular programming approach, I separated each major functionality into different functions to make the codebase more manageable. This required careful data passing between functions, which I handled using vectors and maps to store and transfer information efficiently.

Another significant difficulty was implementing the file moving operation. I relied on the std::filesystem library’s copy and remove methods, which worked well but introduced challenges related to file permissions on Windows. Managing these permissions and ensuring smooth execution required extensive testing and debugging.

Later, I faced an issue with utilizing metadata extracted during the initial organization process. To address this, I integrated an SQLite3 database into the project to persist and retrieve file information. Setting up the database was challenging, especially since I was using the core C API without any wrappers. I had to manually configure CMake, debug several build issues, and implement custom functions to initialize and close database connections. Additionally, I wrote raw SQL queries to design and create the database schema that defines how the file data is stored.

The most complex challenge so far has been sorting files based on their modification time. Because the program uses the copy-and-remove method, the file timestamps change to the current time after the initial organization. To solve this, I rely on the timestamps stored in the first database record instead of the modified ones. This solution works, but it still requires further refinement, which I plan to complete in the second submission.

