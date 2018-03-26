# libBee
## Class Hierarchy
```
Bee
    |
    |---Atomic (bee/concurrency/atomic.h)
    |---SpinLock (bee/concurrency/SpinLock.h)
    |
    |---Queue (bee/data_structure/Queue.h)
    |---ArrayQueue (bee/data_structure/ArrayQueue.h)
    |---NodeQueue (bee/data_structure/NodeQueue.h)
    |---NodeStack (bee/data_structure/NodeStack.h)
    |---List (bee/data_structure/List.h)
    |---SinglyList (bee/data_structure/SinglyList.h)
    |---Pool (bee/data_structure/Pool.h)
    |+--HalfThreadSafe
        |---NodeStack (bee/data_structure/half_thread_safe/htsNodeStack.h)
    |+--ThreadSafe
        |---NodeStack (bee/data_structure/thread_safe/tsNodeStack.h)
```