// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
Car* newCar = new Car{ light, nullptr, nullptr };
if (!first) {
first = newCar;
first->next = first;
first->prev = first;
} else {
Car* last = first->prev;
last->next = newCar;
newCar->prev = last;
newCar->next = first;
first->prev = newCar;
}
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
} while (crnt != first);
}
}
