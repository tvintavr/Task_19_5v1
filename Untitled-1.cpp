#include <iostream>
#include <fstream>
#include <vector>

struct Question {
    std::string question;
    std::string answer;
};

void readQuestions(const std::string& filePath, std::vector<Question>& questions) {
    std::ifstream file(filePath);
    if (!file) {
        std::cout << "Cannot open" << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        
        Question question;
        question.question = line;
        std::getline(file, question.answer);
        
        questions.push_back(question);
    }
}

int main() {
    const int numSectors = 13;
    int currentSector = 0;
    
    std::vector<Question> questions;
    readQuestions("questions.txt", questions);
    
    int playerScore = 0;
    int viewersScore = 0;
    
    while (playerScore < 6 && viewersScore < 6) {
        std::cout << "Current sector: " << currentSector << std::endl;
        
        Question& question = questions[currentSector % numSectors];
        std::cout << "Question: " << question.question << std::endl;
        
        std::string playerAnswer;
        std::cout << "Write your answer: ";
        std::cin >> playerAnswer;
        
        if (playerAnswer == question.answer) {
            std::cout << "Right! You get a score!" << std::endl;
            playerScore++;
        } else {
            std::cout << "Wrong! Viewers get a score!" << std::endl;
            viewersScore++;
        }
        
        currentSector++;
    }
    
    if (playerScore >= 6) {
        std::cout << "Experts win!" << std::endl;
    } else {
        std::cout << "Viewers win!" << std::endl;
    }
}