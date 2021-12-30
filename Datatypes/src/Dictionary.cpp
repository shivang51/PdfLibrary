#include "Dictionary.h"

namespace PdfLib::DataType::Dictionary
{
    template <class KeyType, class ValueType>
    Entry<KeyType, ValueType>::Entry(KeyType key, ValueType value) {
        this->key = key;
        this->value = value;
    }

    template <class KeyType, class ValueType>
    Entry<KeyType, ValueType>::Entry() {
    }

    template <class KeyType, class ValueType>
    Entry<KeyType, ValueType>::~Entry() {

    }

    template<class KeyType, class ValueType>
    KeyType Entry<KeyType, ValueType>::GetKey()
    {
        return this->key;
    }

    template<class KeyType, class ValueType>
    ValueType Entry<KeyType, ValueType>::GetValue()
    {
        return this->value;
    }
    template<class KeyType, class ValueType>
    void Entry<KeyType, ValueType>::SetValue(ValueType value)
    {
        this->value = value;
    }
    template<class KeyType, class ValueType>
    void Entry<KeyType, ValueType>::SetKey(KeyType key)
    {
        this->key = key;
    }
}

namespace PdfLib::DataType::Dictionary
{

    template<class KeyType, class ValueType>
    Dictionary<KeyType, ValueType>::Dictionary()
    {

    }

    template<class KeyType, class ValueType>
    Dictionary<KeyType, ValueType>::~Dictionary()
    {

    }

    template<class KeyType, class ValueType>
    bool Dictionary<KeyType, ValueType>::AddEntry(Entry<KeyType, ValueType> Entry)
    {
        if ( this->KeyExsist(Entry.GetKey()) )
            return false;
        this->dict.push_back(Entry);
        return true;
    }

    template<class KeyType, class ValueType>
    bool Dictionary<KeyType, ValueType>::SetValue(KeyType key, ValueType value)
    {
        if ( this->KeyExsist(key) )
        {
            auto ent = GetEntryP(key);
            ent->SetValue(value);
            return true;
        }
        return false;
    }

    template<class KeyType, class ValueType>
    Entry<KeyType, ValueType> Dictionary<KeyType, ValueType>::GetEntry(KeyType key)
    {
        for ( auto ent : this->dict )
        {
            if ( ent.GetKey() == key )
            {
                return ent;
            }
        }
        return Entry<KeyType, ValueType>("","");
    }

    template<class KeyType, class ValueType>
    Entry<KeyType, ValueType>* Dictionary<KeyType, ValueType>::GetEntryP(KeyType key)
    {
        for ( int i = 0; i < this->dict.size(); i++)
        {
            auto ent = this->dict.data() + i;
            if ( ent->GetKey() == key )
            {
                return ent;
            }
        }
        return nullptr;
    }

    template<class KeyType, class ValueType>
    ValueType Dictionary<KeyType, ValueType>::GetValue(KeyType key)
    {
        for ( auto ent : this->dict )
        {
            if ( ent.GetKey() == key )
            {
                return ent.GetValue();
            }
        }

        return ValueType();
    }

    template<class KeyType, class ValueType>
    bool Dictionary<KeyType, ValueType>::KeyExsist(KeyType key)
    {
        for ( auto ent : this->dict )
        {
            if ( ent.GetKey() == key )
            {
                return true;
            }
        }
        return false;
    }
    template<class KeyType, class ValueType>
    std::vector<KeyType> Dictionary<KeyType, ValueType>::GetKeys()
    {
        std::vector<KeyType> keys = { };

        for ( auto ent : this->dict )
            keys.push_back(ent.GetKey());

        return keys;
    }

    template<class KeyType, class ValueType>
    std::vector<Entry<KeyType, ValueType>> Dictionary<KeyType, ValueType>::GetEntries()
    {
        return this->dict;
    }
}