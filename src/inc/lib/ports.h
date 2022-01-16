#pragma once
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
static inline uint8_t inb(uint16_t port)
{
	uint8_t ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}
static inline void outb(uint16_t port, uint8_t data)
{
	asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
}

static inline uint16_t inw(uint16_t port)
{
	uint16_t ret;
	asm volatile("inw %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}
static inline void outw(uint16_t port, uint16_t data)
{
	asm volatile("outw %0, %1" : : "a"(data), "Nd"(port));
}

static inline uint32_t inl(uint16_t port)
{
	uint32_t ret;
	asm volatile("inl %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}
static inline void outl(uint16_t port, uint32_t data)
{
	asm volatile("outl %0, %1" : : "a"(data), "Nd"(port));
}

static inline void inba(uint16_t port, uint8_t* buffer, size_t size)
{
	asm volatile("rep insb" : : "D"(buffer), "d"(port), "c"(size));
}
static inline void outba(uint16_t port, uint8_t* buffer, size_t size)
{
	asm volatile("rep outsb" : : "S"(buffer), "d"(port), "c"(size));
}

static inline void inwa(uint16_t port, uint16_t* buffer, size_t size)
{
	asm volatile("rep insw" : : "D"(buffer), "d"(port), "c"(size));
}
static inline void outwa(uint16_t port, uint16_t* buffer, size_t size)
{
	asm volatile("rep outsw" : : "S"(buffer), "d"(port), "c"(size));
}

static inline void inla(uint16_t port, uint32_t* buffer, size_t size)
{
	asm volatile("rep insl" : : "D"(buffer), "d"(port), "c"(size));
}
static inline void outla(uint16_t port, uint32_t* buffer, size_t size)
{
	asm volatile("rep outsl" : : "S"(buffer), "d"(port), "c"(size));
}
#ifdef __cplusplus
}
#endif