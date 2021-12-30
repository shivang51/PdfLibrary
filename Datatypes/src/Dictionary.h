#pragma once

#include <vector>
namespace PdfLib::DataType::Dictionary
{
    template <class KeyType, class ValueType>
    class Entry
    {
    public:
        Entry(KeyType key, ValueType value);
        Entry();
        ~Entry();

        KeyType GetKey();
        ValueType GetValue();

        void SetValue(ValueType value);
        void SetKey(KeyType key);

    private:
        KeyType key;
        ValueType value;
    };

    template <class KeyType, class ValueType>
    class Dictionary
    {
    public:
        Dictionary();
        ~Dictionary();

        bool AddEntry(Entry<KeyType, ValueType> Entry);

        /**
        * Sets the value of Entry with the given key but the given key should exist.
        * @param key : key for which you want to set the value.
        * @returns true if given key was valid and false if no Entry with the given key exists.
        **/
        bool SetValue(KeyType key, ValueType value);

        /**
        * Returns the value associated with the given key.
        * @param key : key for which you want the value.
        * @returns Value associated with the given key.
        **/
        Entry<KeyType, ValueType> GetEntry(KeyType key);

        /**
        * Returns the value associated with the given key.
        * @param key : key for which you want the value.
        * @returns Value associated with the given key.
        **/
        ValueType GetValue(KeyType key);

        /**
        * Checks if Entry with given key exists.
        * @param key - name of key to check .
        * @returns true if key exist and false is returned if no Entry with the given key exsist.
        **/
        bool KeyExsist(KeyType key);

        /**
        * Returns all the keys in the dictionary.
        * @returns Vector of KeyType which contains all the dictionary.
        **/
        std::vector<KeyType> GetKeys();

        /**
        * Returns all the entries in the dictionary.
        * @returns Vector which contains all the entries.
        **/
        std::vector<Entry<KeyType, ValueType>> GetEntries();

    private:
        std::vector<Entry<KeyType, ValueType>> dict = {};
        Entry<KeyType, ValueType>* GetEntryP(KeyType key);

    };
}
#include "Dictionary.cpp"