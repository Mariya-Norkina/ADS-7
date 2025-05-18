// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

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
const Car* crnt = first;
do {
length++;
crnt = crnt->next;
} while (crnt != first);
return length;
}

int Train::getOpCount() {
return countOp;
}

Train::~Train() {
if (first) {
Car* crnt = first;
Car* next;
do {
next = crnt->next;
delete crnt;
crnt = next;
} while (current != first);
}
}
