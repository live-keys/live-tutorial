TEMPLATE = subdirs

# In case LiveCV was cloned here, include it to be build with the project

exists($$PWD/livecv):SUBDIRS += $$PWD/livecv

