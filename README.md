# CS 1428 Semester Project Proposal
Student Name: Md Siam Ahmed <br>
Course: CS 1428 – Foundations of Computer Science I (Honor) <br>
Date: September 21, 2025 <br>
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
#### Goal
Create an intelligent file organization system that saves users hours of manual work while
maintaining accuracy and providing customizable organization rules.
### 3. Key Features and Requirements
#### Core Features:
1. Intelligent Content Analysis
* Parse file contents (not just names/extensions) to understand document types
- Recognize common document categories: invoices, receipts, photos, music,
videos, documents, etc.
- Extract meaningful information like dates, document types, and categories from
file content
2. Automated Folder Structure Creation
- Dynamically create organized folder hierarchies based on file analysis
- Examples: "Documents/Invoices/2025/September",
"Media/Photos/2024/Vacation", "Downloads/Software/Utilities"
- Maintain consistent naming conventions and avoid duplicate folders
3. Customizable Organization Rules
- Allow users to set specific rules (e.g., "All .pdf files containing 'invoice' →
Invoices folder")
- User-defined folder structures and naming patterns
- Rule priority system for handling conflicts
- Save and load different organization profiles for different use cases
Additional Features:
- Batch Processing: Handle hundreds of files efficiently
- Progress Tracking: Real-time progress display during organization
4. Technical Challenges
### Algorithm Complexity:
- File Content Parsing: Implementing text extraction from various file types (PDF, DOCX,
images)
- Pattern Recognition: Developing algorithms to identify document types and extract
relevant metadata
- Conflict Resolution: Handling cases where files could belong to multiple categories
Data Structures:
- Hash Maps (std::unordered_map): Store file extension mappings, keyword-to-category
associations, and user-defined rules for O(1) lookup time
- Binary Search Trees (std::map): Organize files by date/time for chronological folder
creation, maintain sorted rule priorities
- Vectors (std::vector): Store lists of files to process, batch operations for file
movements, and maintain processing queues
- Stacks: Track folder creation hierarchy and manage recursive directory traversal during
file scanning
- Priority Queues: Handle file processing order based on file size, type priority, or
user-defined importance levels
#### File System Operations:
- Safe File Movement: Ensuring no data loss during file operations
- Permission Handling: Managing file system permissions across different operating
systems
- Large File Processing: Efficiently handling large files and directories
User Interface:
- Real-time Updates: Displaying organization progress and results
- Rule Configuration Interface: Creating an intuitive system for users to set custom rules
### 5. AI Tools Usage Plan
#### Specific AI Tool Integration:
1. Claude AI (Code Architecture & Problem Solving)
- Assist with overall system design and data structure selection
- Help brainstorm efficient algorithms for file categorization and content analysis
- Support complex problem-solving when handling edge cases in file operations
2. CLion AI Assistant (Code Completion & Debugging)
- Utilize CLion's integrated AI-powered code completion for efficient C++
development
- Leverage intelligent code suggestions and auto-completion during
implementation
- Use AI-assisted debugging features to identify and resolve runtime issues
- Take advantage of automated refactoring suggestions and code quality
improvements
3. Gemini API (Content Understanding & Analysis)
- Integrate directly into the application for intelligent file content analysis
- Use Gemini's natural language processing to understand document types and
contexts
- Analyze file contents to extract meaningful metadata (dates, document types,
categories)
- Enable the system to recognize invoices, receipts, letters, and other document
types beyond simple keyword matching
Implementation Strategy:
- Development Phase: Use Claude and CLion AI for coding assistance and
debugging
- Runtime Integration: Embed Gemini API calls for live content analysis of user
files
- Privacy Considerations: Ensure user consent before sending file contents to
external APIs
#### Responsible Usage and Documentation:
- All AI-generated code will be thoroughly reviewed, tested, and modified to fit
project requirements
- API usage will be clearly documented with rate limiting and error handling
- Code comments will indicate where AI assistance was used and how it was
adapted
- Focus on understanding AI suggestions rather than blind implementation
- Maintain academic integrity by being prepared to explain all code components
6. Milestones and Submissions
### Submission 1: Core Functionality (Due: October 26, 2025)
#### Milestone 1 Deliverables:
- Basic file analysis system that can identify file types and extract simple metadata
- Core organization engine that can move files into predefined folder structures
- Simple rule system for basic file categorization (by extension and basic keywords)
- Command-line interface for testing core functionality
- Ability to process a target folder and organize files into basic categories (Documents,
Images, Audio, Video, Archives, Other)
Submission 2: Advanced Features and GUI (Due: November 30, 2025)
#### Milestone 2 Deliverables:
- Advanced content analysis with context understanding (recognizing invoices, receipts,
etc.)
- User-friendly graphical interface with progress tracking
- Customizable rule system where users can define their own organization logic
- Backup and undo functionality
- Complete documentation, including a user guide and technical documentation
- Comprehensive testing with various file types and edge cases
