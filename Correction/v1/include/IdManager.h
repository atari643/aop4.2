#ifndef IDMANAGER_H
#define IDMANAGER_H
#include <deque>

class IdManager
{
private:
    std::deque<int> m_id_libres;
    int m_curId;

public:
    IdManager();

    int obtenir();
    void liberer(int id);
};
#endif // IDMANAGER_H