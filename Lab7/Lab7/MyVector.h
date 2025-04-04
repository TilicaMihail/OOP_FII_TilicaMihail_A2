#pragma once

template<typename T>
class MyVector
{
private:
	T* vec;
	int len, max_len;

	void resize() {
		max_len *= 2;
		T* newVec = new T[max_len];
		for (int i = 0; i < len; i++)
			newVec[i] = vec[i];
		delete[] vec;
		vec = newVec;
	}
public:
	MyVector() : max_len(1), len(0) {
		vec = new T[max_len];
	}

	~MyVector() {
		delete[] vec;
	}

	int	count() {
		return len;
	}

	void push(const T &newObj) {
		if (len == max_len) resize();
		vec[len] = newObj;
		len++;
	}

	T pop() {
		if (len == 0)
			return 0;
		else
			return vec[--len];
	}

	void remove(int index) {
		if (index < 0 && index > len - 1)
			return;
		for (int i = index; i < len && i < max_len - 1; i++)
			vec[i] = vec[i + 1];
		len--;
	}

	void insert(int index, const T& value) {
		if (index < 0 && index > len - 1)
			return;
		for (int i = len; i >= index + 1; i--)
			vec[i] = vec[i - 1];
		vec[index] = value;
		len++;
	}

	T get(int index) {
		if (index < 0 && index > len - 1)
			return 0;
		return vec[index];
	}

	void set(int index, const T& value) {
		if (index < 0 && index > len - 1)
			return;
		vec[index] = value;
	}

	int firstIndexOf(const T& value, bool (*cmp)(const T&, const T&) = 0) {
		if (!cmp) cmp = [](const T& a, const T& b) { return a == b; };
		for (int i = 0; i < len; ++i) {
			if (cmp(vec[i], value)) return (int)i;
		}
		return -1;
	}

	void sort(bool (*cmp)(const T&, const T&) = 0) {
		if (!cmp) cmp = [](const T& a, const T& b) { return a < b; };
		for(int i = 0; i < len - 1; i ++)
			for(int j = i; j < len; j ++)
				if (cmp(vec[j], vec[i])) {
					T temp = vec[j];
					vec[j] = vec[i];
					vec[i] = temp;
				}
	}
};

