#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <utility>
#include "utils.hpp"

namespace ft
{
    template <class K, class V>
    class MapIterator
    {
        public:
                typedef ft::pair<K, V> value_type;
                typedef ft::pair<K, V>& reference;
                typedef BNode<K, V>* pointer;
        protected:
                pointer _ptr;
        private:
                pointer _successor(pointer ptr)
                {
                    pointer next;
                    if (!ptr->rightNode)
                    {
                        next = ptr;
                        while (next->parentNode && next == next->parentNode->rightNode)
                            next = next->parentNode;
                        next = next->parentNode;
                    }
                    else
                    {
                        next = ptr->rightNode;
                        while (next->leftNode)
                            next = next->leftNode;
                    }
                    return (next);
                };
                pointer _predecessor(pointer ptr)
                {
                    pointer next;
                    if (!ptr->leftNode)
                    {
                        next = ptr;
                        while (next->parentNode && next == next->parentNode->leftNode)
                            next = next->parentNode;
                        next = next->parentNode;
                    }
                    else
                    {
                        next = ptr->leftNode;
                        while (next->rightNode)
                            next = next->rightNode;
                    }
                    return (next);
                };
        public:
                MapIterator(void) : _ptr(0) {};
                MapIterator(const pointer ptr) : _ptr(ptr) {};
                MapIterator(const MapIterator &src) { *this = other; };
                MapIterator &operator=(const MapIterator &other)
                {
                    _ptr = other._ptr;
                    return (*this);
                };
                pointer node(void) { return (_ptr); };
                value_type &operator*(void) { return (_ptr->pair); };
                value_type *operator->(void) { return (&_ptr->pair); };
                bool    operator==(const MapIterator<K, V> &other) { return (this->_ptr == other._ptr); };
                bool    operator!=(const MapIterator<K, V> &other) { return (!(*this == other)); };
                bool    operator>(const MapIterator<K, V> &other) { return (this->_ptr > other._ptr); };
                bool    operator<(const MapIterator<K, V> &other) { return (this->_ptr < other._ptr); };
                bool    operator>=(const MapIterator<K, V> &other) { return (this->_ptr >= other._ptr); };
                bool    operator<=(const MapIterator<K, V> &other) { return (this->_ptr <= other._ptr); };
                MapIterator &operator++(void)
                {
                    _ptr = _successor(_ptr);
                    return (*this);
                };
                MapIterator &operator--(void)
                {
                    _ptr = _predecessor(_ptr);
                    return (*this);
                };
                MapIterator operator++(int)
                {
                    MapIterator _ret = *this;
                    this->operator++();
                    return (_ret);
                };
                MapIterator operator--(int)
                {
                    MapIterator _ret = *this;
                    this->operator--();
                    return (_ret);
                };
    };
    template <class K, class V>
    class ConstMapIterator
    {
        public:
                typedef ft::pair<K, V>  value_type;
                typedef ft::pair<K, V>& reference;
                typedef BNode<K, V>* pointer;
        protected:
                pointer _ptr;
        private:
                pointer _successor(pointer ptr)
                {
                    pointer next;

                    if (!ptr->rightNode)
                    {
                        next = ptr;
                        while (next->parentNode && next == next->parentNode->rightNode)
                            next = next->parentNode;
                        next = next->parentNode;
                    }
                    else
                    {
                        next = ptr->rightNode;
                        while (next->leftNode)
                            next = next->leftNode;
                    }
                    return (next);
                };
                pointer _predecessor(pointer ptr)
                {
                    pointer next;

                    if (!ptr->leftNode)
                    {
                        next = ptr;
                        while (next->parentNode && next == next->parentNode->leftNode)
                            next = next->parentNode;
                        next = next->parentNode;
                    }
                    else
                    {
                        next = ptr->leftNode;
                        while (next->rightNode)
                            next = next->rightNode;
                    }
                    return (next);
                };
    };
}

#endif