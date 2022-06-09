template <typename T>
MyList<T>::MyList() {
    m_sentinel = new Node<T>(m_sentinel, m_sentinel);
    m_sentinel->m_next = m_sentinel;
    m_sentinel->m_prev = m_sentinel;//
    m_size = 0;
}

template <typename T>
MyList<T>::~MyList() {
    clear();
    delete m_sentinel;
}

template <typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source) {
    clear();
    Node<T> * p = source.m_sentinel->m_next;
    for(int i = 0; i < source.m_size; i++) {
        push_back(p->m_element);
        p=p->m_next;
    }
    return *this;
}

template <typename T>
MyList<T>::MyList(const MyList<T> &source) {
    m_sentinel = new Node<T>(m_sentinel, m_sentinel);
    m_size = 0;
    Node<T> * p = source.m_sentinel->m_next;
    for(int i = 0; i < source.m_size; i++) {
        push_back(p->m_element);
        p = p->m_next;
    }
}

template <typename T>
T & MyList<T>::front() {
    return m_sentinel->m_next->m_element;
}

template <typename T>
T & MyList<T>::back() {
    Node<T> * temp = m_sentinel;
    for(int i = 0; i < m_size; i++)
        temp = temp->m_next;
    return temp->m_element;
}

template <typename T>
void MyList<T>::assign(int count, const T &value) {
    for(int i = 0; i < count; i++) {
        push_back(value);
    }
}

template <typename T>
void MyList<T>::clear() {
    Node<T> * p = m_sentinel->m_next;
    for(int i = 0; i < m_size; i++) {
        delete p;
        p = p->m_next;
    }
    m_size = 0;
}

template <typename T>
void MyList<T>::push_front(const T &x) {
    if (m_size == 0) {
        m_sentinel->m_next = new Node<T>(x, m_sentinel, nullptr);
    } else {
        m_sentinel->m_next->m_prev = new Node<T>(x, m_sentinel, m_sentinel->m_next);
        m_sentinel->m_next = m_sentinel->m_next->m_prev;
    }
    m_size++;
}

template <typename T>
void MyList<T>::push_back(const T &x) {
    Node<T> * temp = m_sentinel;
    for(int i = 0; i < m_size; i++)
        temp = temp->m_next;
    temp->m_next = new Node<T>(x, temp, nullptr);
    m_size++;
}

template <typename T>
void MyList<T>::pop_back() {
    if (m_size != 0) {
        Node<T> * temp = m_sentinel;
        for(int i = 0; i < m_size; i++)
            temp = temp->m_next;
        temp->m_prev->m_next = nullptr;
        delete temp;
        m_size--;
    }
}

template <typename T>
void MyList<T>::pop_front() {
    if (m_size > 0) {
		Node<T> * temp = m_sentinel->m_next;
        m_sentinel->m_next = m_sentinel->m_next->m_next;
        m_sentinel->m_next->m_prev = m_sentinel;
        delete temp;
        m_size--;
    }
}

template <typename T>
void MyList<T>::insert(int i, const T &x) {
    Node<T> * temp = m_sentinel->m_next;
    for(int r = 1; r < i; r++)
        temp = temp->m_next;
    Node<T> * p = new Node<T>(x, temp->m_prev, temp);
    temp->m_prev->m_next = p;
    temp->m_prev = p;
    m_size++;
}

template <typename T>
void MyList<T>::remove(T value) {
    Node<T> * temp = m_sentinel;
    Node<T> * hand = m_sentinel;
    for(int i = 0; i < m_size; i++) {
        temp = temp->m_next;
        hand = hand->m_next;
        if (temp->m_element == value && i == m_size-1) {
            pop_back();
        } else if (temp->m_element == value){
            hand = hand->m_next;
            temp->m_prev->m_next = temp->m_next;
            temp->m_next->m_prev = temp->m_prev; 
            delete temp;
            m_size--;
            hand = hand->m_prev;
            temp = hand;
        }
    }
}

template <typename T>
void MyList<T>::erase(int i) {
    Node<T> * temp = m_sentinel->m_next;
    for(int r = 0; r < i; r++)
        temp = temp->m_next;
    temp->m_prev->m_next = temp->m_next;
    temp->m_next->m_prev = temp->m_prev;
    delete temp;
    m_size--;
}//

template <typename T>
void MyList<T>::reverse() {
    if (m_size > 1) {
        Node<T> * p = m_sentinel->m_next;
        MyList<T> templist;
        for(int i = 1; i < m_size+1; i++) {
            templist.push_front(p->m_element);
            p = p->m_next;
        }
        clear();
        Node<T> * r = templist.m_sentinel->m_next;
        for(int i = templist.m_size+1; i > 1; i--) {
            push_back(r->m_element);
            r = r->m_next;
        }

    }
}

template <typename T>
bool MyList<T>::empty() {
    bool result;
    (m_size > 0) ? result = false : result = true;
    return result;
}

template <typename T>
int MyList<T>::size() {
    return m_size;
}