# 🎮 Advanced Hangman Game in C

## 📌 Project Description
This project is an advanced version of the classic Hangman game implemented in C.  
It is designed with intelligent gameplay features, domain-specific vocabulary (Quantum Technology and Signal Systems), and a dynamic clue system to enhance user interaction.

---

## 🚀 Features

- 🔤 Letter-by-letter guessing system  
- 🧠 Full word guessing (allowed after 3rd attempt)  
- 🎯 6 progressive clues for each word  
  - First 3 clues are intentionally confusing  
  - Next 2 clues provide better hints  
  - Final clue can be unlocked using points  
- 💡 Reveal a random letter using `!` (cost: 20 points)  
- 🔐 Final clue unlock using `?` (cost: 50 points)  
- ⚠️ Smart feedback system:
  - Correct guess → Positive message  
  - Close guess → Warning message  
  - Incorrect guess → Penalty  
- 📊 Score tracking system  
- 🔁 Replay option  
- 🎨 Colored output for better UI  

---

## 🧪 Technologies Used

- C Programming Language  
- Standard Libraries:
  - stdio.h  
  - string.h  
  - stdlib.h  
  - ctype.h  
  - time.h  

---

## 🎯 Game Rules

1. The player has **6 attempts** to guess the word.  
2. The word is displayed with blanks (`_ _ _`).  
3. A new clue is shown in every attempt.  
4. The player can:
   - Enter a **single letter**  
   - Guess the **full word** (after 3rd attempt)  
5. Special options:
   - `!` → Reveal a letter (-20 points)  
   - `?` → Unlock final clue (-50 points)  
6. If all attempts are used:
   - The correct word is displayed in **uppercase and highlighted format**  

---

## ▶️ How to Run

1. Compile the program:
   ```bash
   gcc main.c -o game



## 📌 Future Improvements
- 🎚️ Introduce multiple difficulty levels (Easy, Medium, Hard) with varying word complexity and attempts  
- 💾 Implement file handling to store and display high scores using persistent storage  
- 🖥️ Develop a graphical user interface (GUI) for enhanced user interaction and visual experience  
- 🌐 Expand the word database with additional domain-specific and interdisciplinary terms  
- 🔊 Add sound effects and animations to improve gameplay engagement

  ## 👩‍💻 Author
S V S Sri Hasini
