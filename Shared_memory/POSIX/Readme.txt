POSIX shared memory
==> The POSIX shared memory API allows processes to communicate information by sharing a region of memory.
==> shm_open - Create and open a new object, or open an existing object.
==> mmap - Map the shared memory object into the virtual address space of the calling process.
==> msync()  flushes  changes made to the in-core copy of a file that was mapped into memory using mmap(2) back to the filesystem.
==> munmap - Unmap the shared memory object from the virtual address space of the calling process.
