/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_DATA_STRUCTURE_SINGLY_LIST_H_
#define BEE_DATA_STRUCTURE_SINGLY_LIST_H_

namespace Bee
{

struct SinglyNode;

class SinglyList
{
public:
	inline SinglyList() noexcept = default;
	inline void reset() noexcept;

	void __fastcall remove(SinglyNode const *p_node) noexcept;

	inline SinglyNode* head() const noexcept;

protected:
	SinglyNode *mp_head = nullptr;
};

void
SinglyList::reset() noexcept
{
	mp_head = nullptr;
}

SinglyNode*
SinglyList::head() const noexcept
{
	return mp_head;
}

} // namespace Bee

#endif // BEE_DATA_STRUCTURE_SINGLY_LIST_H_