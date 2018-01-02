
def selection_sort(arr):

    length = len(arr)
    for i in range(0,length):
        min = i
        for j in range(i,length):
            if arr[min]>arr[j]:
                min = j
        arr[i],arr[min] = arr[min],arr[i]  #swap
    return arr

# arr = [2,5,0,2,2,7,3]
# print(selection_sort(arr))