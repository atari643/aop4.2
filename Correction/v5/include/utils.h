#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
const int LARGEUR = 1200;
const int HAUTEUR = 800;
void decouper(const std::string &str, std::vector<std::string> &tokens, const std::string &delimiters = " ");

#endif // UTILS_H