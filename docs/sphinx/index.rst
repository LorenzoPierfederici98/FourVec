.. Four Vector documentation master file, created by
   sphinx-quickstart on Sun Jan 19 15:54:43 2025.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to Four Vector's documentation!
=======================================

Repo di prova per la documentazione di codice C++ con doxygen e sphinx.

Nella directory del progetto creare una cartella ``docs`` e girare ``doxygen -g``. Questo crea il file DoxyFile; all'interno di questo mettere le opzioni::

   * INPUT = path/to/your_project
   * FILE_PATTERNS = *.cc *.h
   * RECURSIVE = YES
   * GENERATE_HTML = NO
   * GENERATE_XML = YES
   * XML_OUTPUT = xml

Mandare ``doxygen DoxyFile`` dal path in cui è presente il DoxyFile. Creare la cartella di sphinx ``sphinx`` dentro la cartella ``docs``, da questa mandare ``sphinx-quickstart``. Modificare il file ``docs/sphinx/conf.py`` come quello qui di esempio (viene inserita l'estensione per breathe e viene creata una funzione per runnare doxygen). Nel file ``index.rst`` aggiungere un file .rst in cui mettere i file oggetto della documentazione; in questo esempio il file in questione è ``api.rst`` (da creare nello stesso path di index.rst) che ha questa struttura::
   API documentation

   =================

   .. doxygenfile:: four_vec.cc
      :project: Four Vector

Creare il file ``.readthedocs.yaml`` nella directory principale, come quello di esempio, per generare la documentazione con Read the Docs. Nel file ``docs/sphinx/requirements.txt`` possono essere inseriti, oltre a breathe e sphinx, i temi di sphinx diversi da quelli di default, che possono così essere installati ed usati nel file conf.py.


.. toctree::
   :maxdepth: 2
   :caption: Contents:

   api


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
