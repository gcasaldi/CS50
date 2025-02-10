from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    # TODO

    """splitline() method splits strings to lines"""
    aline = a.splitlines()
    bline = b.splitlines()
    common = []

    # to iterate through lines stored in aline and bline and look for similar lines
    for line in aline:
        if line in bline:
            common.append(line)

    return common


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    """sent_tokenize function dissects the sentences from strings"""
    asen = sent_tokenize(a)
    bsen = sent_tokenize(b)
    common = []

    for sent in asen:
        if sent in bsen:
            # to check if similar sentence already exists to avoid duplicate
            if sent not in common:
                common.append(sent)

    return common


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO

    asstring = []
    bsstring = []
    common = []

    # to avoid display of similarities when substring length is longer than string length
    if len(a) and len(b) >= n:

        # iterate through the chars of a
        for i in range(len(a)):
            if a[i+n:]:
                asstring.append(a[i:i+n])

        asstring.append(a[-n:])

        for i in range(len(b)):
            if b[i+n:]:
                bsstring.append(b[i:i+n])

        bsstring.append(b[-n:])


    for sstring in asstring:
        if sstring in bsstring:
            if sstring not in common:
                common.append(sstring)

    return common
