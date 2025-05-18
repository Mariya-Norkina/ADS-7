// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr), currentLength(0) {}

void Train::addCar(bool light) {
if (first == nullptr) {
first = new Car{ light, nullptr, nullptr };
return;
}
if (first->next == nullptr) {
Car* object = new Car{ light, nullptr, nullptr };
first->next = object;
first->prev = object;
object->prev = first;
object->next = first;
return;
}
Car* object = new Car{ light, nullptr, nullptr };
first->prev->next = object;
object->prev = first->prev;
first->prev = object;
object->next = first;
first = object;
}

int Train::getLength() {
if (first == nullptr) {
return 0;
}
int length = 0;
const Car* current = first;
do {
length++;
current = current->next;
} while (current != first);
return length;
}

int Train::getOpCount() {
return countOp;
}

Train::~Train() {
if (first == nullptr) {
return;
}
Car* current = first;
Car* nextCar = nullptr;
Car* last = first->prev;
last->next = nullptr;
while (current != nullptr) {
nextCar = current->next;
delete current;
current = nextCar;
}
first = nullptr;
currentLength = 0;
countOp = 0;
}
