#ifndef FUSION_MAPPING_HASH_ENTRY_H
#define FUSION_MAPPING_HASH_ENTRY_H

#include <macros.h>
#include <vector_math.h>
#include <cuda_runtime_api.h>

struct FUSION_EXPORT HashEntry
{
    FUSION_HOST_AND_DEVICE inline HashEntry();
    FUSION_HOST_AND_DEVICE inline HashEntry(int3 pos, int next, int offset);
    FUSION_HOST_AND_DEVICE inline HashEntry(const HashEntry &);
    FUSION_HOST_AND_DEVICE inline HashEntry &operator=(const HashEntry &);
    FUSION_HOST_AND_DEVICE inline bool operator==(const int3 &) const;
    FUSION_HOST_AND_DEVICE inline bool operator==(const HashEntry &) const;

    int ptr_;
    int offset_;
    int3 pos_;
};

FUSION_HOST_AND_DEVICE inline HashEntry::HashEntry()
    : ptr_(-1), offset_(-1)
{
}

FUSION_HOST_AND_DEVICE inline HashEntry::HashEntry(int3 pos, int ptr, int offset)
    : pos_(pos), ptr_(ptr), offset_(offset)
{
}

FUSION_HOST_AND_DEVICE inline HashEntry::HashEntry(const HashEntry &other)
    : pos_(other.pos_), ptr_(other.ptr_), offset_(other.offset_)
{
}

FUSION_HOST_AND_DEVICE inline HashEntry &HashEntry::operator=(const HashEntry &other)
{
    pos_ = other.pos_;
    ptr_ = other.ptr_;
    offset_ = other.offset_;
    return *this;
}

FUSION_HOST_AND_DEVICE inline bool HashEntry::operator==(const int3 &pos) const
{
    return this->pos_ == pos;
}

FUSION_HOST_AND_DEVICE inline bool HashEntry::operator==(const HashEntry &other) const
{
    return other.pos_ == pos_;
}

#endif