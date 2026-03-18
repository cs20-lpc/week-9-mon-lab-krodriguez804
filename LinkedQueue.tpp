template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if(this->length == 0) {
        throw string("back error: list is empty");
    }

    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    head = nullptr;
    last = nullptr;
    this->length = 0;

    Node* curr = copyObj.head;
    
    while (curr != nullptr) {
        enqueue(curr->value);
        curr = curr->next;
    }

}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (this->length == 0) {
        throw string ("dequeue error: list is empty");
    }

    Node* oldHead = head;

    head = head->next;

    delete oldHead;

    this->length--;

    if (head == nullptr) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);

    if (head == nullptr) {
        head = newNode;
        last = newNode;
    }
    else {
        last->next = newNode;
        last = newNode;        
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (this->length == 0) {
        throw string("front error: list is empty");
    }

    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
