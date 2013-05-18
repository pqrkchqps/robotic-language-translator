template <class T>
class myiterator<T> {
private:
	T *_cur;
	T *_head;
	T *_tail;
	T *_prev;
	T *_next;
public:
	myiterator<T>(T *c, T *h, T *t, T *p, T *n,) {
		_cur = c;
		_head = h;
		_tail = t;
		_prev = p;
		_next = n;
	}

	T &operator*() {
		return _cur;
	}
	
	T operator*() const {
		return *_cur;
	}
	
	T * operator->() {
		return _cur;
	}
	
	T const * operator->() const {
		return _cur;
	}

	myiterator<T> & operator++(){
		if (_next != NULL) {
			_prev = _cur;
			_cur = _next;
			_next = _cur->getNext();
		}
		return this;
	}

	T & begin() {
		return _head;
	}

	T & end() {
		return _tail;
	}
};
