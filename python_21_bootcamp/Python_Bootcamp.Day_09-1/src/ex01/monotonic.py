import ctypes

# Load the C library
libc = ctypes.CDLL('/usr/lib/x86_64-linux-gnu/libc.so.6')

# Structure representing the timespec struct in C
class Timespec(ctypes.Structure):
    _fields_ = [
        ('tv_sec', ctypes.c_longlong),   # Seconds
        ('tv_nsec', ctypes.c_long)       # Nanoseconds
    ]
    
# Define the clock_gettime function signature
clock_gettime = libc.clock_gettime
clock_gettime.argtypes = [ctypes.c_int, ctypes.POINTER(Timespec)]

# Constants for the clock IDs

CLOCK_MONOTONIC = 1  # Represents the monotonic clock


def monotonic():
    # Create a Timespec object
    ts = Timespec()

    # Call clock_gettime with CLOCK_MONOTONIC
    clock_gettime(CLOCK_MONOTONIC, ctypes.pointer(ts))

    # Calculate the time in seconds
    time_seconds = ts.tv_sec + ts.tv_nsec * 1e-9

    return time_seconds

if __name__ == "__main__":
    # Usage example
    start_time = monotonic()

    # Perform some time-dependent operations

    end_time = monotonic()

    elapsed_time = end_time - start_time
    print(f"Elapsed time: {elapsed_time} seconds")