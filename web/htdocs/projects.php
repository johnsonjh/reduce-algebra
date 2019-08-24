<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'Related Projects');

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
	<style type="text/css">
	#main li {
	margin-bottom: 1em
}
	</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'Related Projects');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
	<h2>Projects related to REDUCE</h2>
	<p>There are a number of independent projects that use REDUCE in various ways. These include:</p>
	<ul>
	<li>the <a href="http://www.alltypes.de/">ALLTYPES</a> algebraic language and type system;</li>
	<li>the <a href="http://axiom-wiki.newsynthesis.org/">MathAction</a> collaborative web interface for Axiom, REDUCE and other computer algebra systems;</li>
	<li>the <a href="http://mentorproducts.com/">Mentor Mathematics Advisor</a> for mathematics education;</li>
	<li><a href="http://mtt.sourceforge.net/">MTT</a>, a set of tools for modeling dynamic physical systems using the bond-graph methodology;</li>
	<li><a href="https://github.com/chakravala/Reduce.jl">Reduce.jl</a>, an interface for calling REDUCE from the Julia language for symbolic manipulation;</li>
	<li>the <a href="https://github.com/agraef/pure-lang/wiki/ScientificComputing">Pure</a> programming language, which has bindings for REDUCE, providing a very interesting environment for doing computer-powered science.</li>
	</ul>
	<p>The following projects were distributed independently but are now available from the REDUCE SourceForge project:</p>
	<ul>
	<li><a href="http://www.redlog.eu/">Redlog</a> &ndash; Computing with Logic &ndash; is now an integral part of REDUCE;</li>
	<li><a href="http://cds.cern.ch/record/438562/files/0005081.pdf">Ortocartan</a> is a <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/contrib/ortocartan/">set of programs</a> for algebraic calculations in relativity, implemented in the Lisp underlying REDUCE;</li>
	<li><a href="reduce-ide/">REDUCE IDE</a> is an <u>I</u>ntegrated <u>D</u>evelopment <u>E</u>nvironment for the <a href="http://www.gnu.org/software/emacs/emacs.html">GNU Emacs</a> editor.</li>
	</ul>
	<h2>Other computer algebra systems</h2>
	<p>Wikipedia provides a fairly comprehensive <a href="https://en.wikipedia.org/wiki/List_of_computer_algebra_systems">list of computer algebra systems</a>, but it does not include the following:</p>
	<ul>
	<li><a href="http://www.mathpiper.org/">MathPiper</a></li>
	<li><a href="http://polybori.sourceforge.net/">PolyBoRi</a> &ndash; Polynomials over Boolean Rings</li>
	<li><a href="https://download.cnet.com/SymbMath/3000-2053_4-10002619.html">SymbMath</a>, which has evolved into the <a href="http://math.drhuang.com/science/mathematics/software/">Math Handbook Calculator</a></li>
	</ul>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
