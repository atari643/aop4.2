#include "IdManager.h"

using namespace std;


IdManager::IdManager() : m_curId(0) {}

int IdManager::obtenir() {
    if (!m_id_libres.empty()){
        int id = m_id_libres.front();
        m_id_libres.pop_front();
        return id;
    }
    return m_curId++;
}

void IdManager::liberer(int id){
    m_id_libres.push_back(id);
}