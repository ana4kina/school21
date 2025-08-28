import sqlite3

conn = sqlite3.connect('quiz.db')
cursor = conn.cursor()

cursor.execute('''
    CREATE TABLE quiz (
        id INTEGER PRIMARY KEY,
        question TEXT,
        response_a TEXT,
        response_b TEXT,
        response_c TEXT,
        response_d TEXT,
        correct_response TEXT
    )
''')

questions = [
    ("What is the capital of France?", "Paris", "London", "Rome", "Berlin", 'Paris'),
    ("Who painted the Mona Lisa?", "Leonardo da Vinci", "Vincent van Gogh", "Pablo Picasso", "Michelangelo", 'Leonardo da Vinci'),
    ('What is the chemical symbol for gold?', 'Au', 'Ag', 'Fe', 'Cu', 'Au'),
    ('Which country won the FIFA World Cup in 2018?', 'France', 'Germany', 'Brazil', 'Argentina', 'France'),
    ('Who is the current CEO of Tesla?', 'Elon Musk', 'Mark Zuckerberg', 'Tim Cook', 'Jeff Bezos', 'Elon Musk'),
    ('Which famous scientist developed the theory of relativity?', 'Albert Einstein', 'Isaac Newton', 'Galileo Galilei', 'Nikola Tesla', 'Albert Einstein'),
    ('Which continent is known as the "Dark Continent"?', 'Africa', 'Asia', 'Europe', 'Australia', 'Africa'),
    ('Who is the author of the Harry Potter book series?', 'J.K. Rowling', 'Stephen King', 'George R.R. Martin', 'Roald Dahl', 'J.K. Rowling'),
    ('Who wrote the novel "Pride and Prejudice"?', 'Jane Austen', 'Charles Dickens', 'F. Scott Fitzgerald', 'Mark Twain', 'Jane Austen'),
    ('Which planet is known as the "Red Planet"?', 'Mars', 'Jupiter', 'Saturn', 'Venus', 'Mars'),
]

cursor.executemany('INSERT INTO quiz (question, response_a, response_b, response_c, response_d, correct_response) VALUES (?, ?, ?, ?, ?, ?)', questions)

conn.commit()
conn.close()
