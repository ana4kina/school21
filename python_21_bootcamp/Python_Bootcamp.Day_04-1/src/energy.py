import itertools

def stringer(args):
    return f"plug {args[0]} into {args[1]} using {args[2]}" if all(args) else f'weld {args[0]} to {args[1]} without plug'

def filtringer(val):
    return isinstance(val, str)


def fix_wiring(cables, sockets, plugs):
    return (map(stringer, filter(lambda x: all(x[:-1]), itertools.zip_longest(filter(filtringer, cables), filter(filtringer, sockets), filter(filtringer, plugs)))))


if __name__ == "__main__":
    plugs = ['plug1', 'plug2', 'plug3']
    sockets = ['socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable1', 'cable2', 'cable3', 'cable4']
    lst = list(fix_wiring(cables, sockets, plugs))
    print(*lst, sep='\n')

    plugs = ['plug1', 'plug2', 'plug3']
    sockets = ['socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable1', 'cable2', 'cable3', 'cable4']

    for c in fix_wiring(cables, sockets, plugs):
        print(c)

    plugs = ['plugZ', None, 'plugY', 'plugX']
    sockets = [1, 'socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable2', 'cable1', False]
    for c in fix_wiring(cables, sockets, plugs):
        print(c)
    
    plugs = ['plugZ', 1, None, 'plugY', 'plugX']
    sockets = [1, 'socket1', 'socket2', 2, 'socket3', 'socket4']
    cables = ['cable2', None, 'cable1', False]
    for c in fix_wiring(cables, sockets, plugs):
        print(c)