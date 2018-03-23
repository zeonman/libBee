/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_DATA_STRUCTURE_LIST_H_
#define BEE_DATA_STRUCTURE_LIST_H_

namespace Bee
{

struct DoublyNode;

class List
{
public:
	inline List() noexcept = default;
	inline void reset() noexcept;

	void __fastcall push_front(DoublyNode *p_node) noexcept;
	DoublyNode* pop_front() noexcept;
	void __fastcall push_back(DoublyNode *p_node) noexcept;
	DoublyNode* pop_back() noexcept;
	void __fastcall remove(DoublyNode const *p_node) noexcept;

	inline DoublyNode* head() const noexcept;
	inline DoublyNode* tail() const noexcept;

protected:
	DoublyNode *mp_head = nullptr;
	DoublyNode *mp_tail = nullptr;
};

void
List::reset() noexcept
{
	mp_head = mp_tail = nullptr;
}

DoublyNode*
List::head() const noexcept
{
	return mp_head;
}

DoublyNode*
List::tail() const noexcept
{
	return mp_tail;
}

} // namespace Bee

#endif // BEE_DATA_STRUCTURE_LIST_H_