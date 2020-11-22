#include "hashtable.h"


//template <>
//QString& HashTable<QString>::StdToType(const std::string &agreg) const{
//    QString res = QString(QString::fromStdString(agreg));
//    return res;
//}

//template <>
//std::string& HashTable<QString>::TypeToStd(const QString &agreg )const{
//    std::string res = QString(agreg).toStdString();
//    return res;
//}


//template <class T>
//int HashTable<T>::HashFunction(const T& str, int table_size, const int key) const
//{
//    //::string s = this->TypeToStd(str);
//    int hash_result = 0;
//    /*for (int i = 0; i != s.length(); ++i){
//        int code = s[i];
//        hash_result = (key * hash_result + code) % table_size;
//    }*/

//    hash_result = (hash_result * 2 + 1) % table_size;
//    return hash_result;
//}
